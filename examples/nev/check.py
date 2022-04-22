
import re
from time import process_time_ns
unquoted = '[^\'"]%s[^\'"]?'

reSpaces = re.compile('\\s+')
pyfile = open('sample.py', 'w')
docs = '''
MAIL : 
	MAIL_HEADER _MAIL_BODY 
	{
		_MAIL();
	}
	| error
	{
		_MLTYPE_XXXX(1);
	}
	| MAIL_HEADER error
	{
		_MLTYPE_XXXX(2);
	}
	| MAIL_HEADER _MAIL_BODY error
	{
		_MLTYPE_XXXX(3);
	}
;


MAIL_HEADER :
	MAIL_HEADER_LINES LT_RETURN_HEADER {
		_MAIL_HEADER();
	}
;


MAIL_HEADER_LINES :
	  LT_HEADER_ONE_LINE 
	| MAIL_HEADER_LINES LT_HEADER_ONE_LINE 
;


_MAIL_BODY :
	  MAIL_BODY
;
'''
docs = re.split("\n;", docs)
rules = []

doc ="""
        CMD_LINE_RR
            : CMD_TOKEN_RR LT_INTVAL LT_COMMA LT_TEXT_EX LT_RETURN
            | MD_TOKEN_RR LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_RETURN
            | MD_TOKEN_RR LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_COMMA LT_INTVAL LT_RETURN
        """

doc = doc.strip()
# added by Eugene Oden
#target, options = doc.split(":")
# doc = re.sub(";", "", doc)

s = re.split(":", doc)

target, options = s
target = target.strip()

options = options.strip()
tmp = []
#opts = options.split("|")
r = unquoted % r"\|"
opts1 = re.split(r, " " + options)

# opts1 = filter(lambda s: s != '', map(str.strip, re.split(r, " " + options)))

for o in opts1:
	o = o.strip()
	tmp.append(reSpaces.split(o))
options = tmp

rules.append((target, options))

# and render rules to grammar file
for rule in rules:
	# print("rule 0", rule[1])
	try:
		# print("%s\n    : " % rule[0])
		options = []
		idx = 0
		for option in rule[1]:
			nterms = len(option)
			if nterms == 1 and option[0] == '':
				nterms = 0
				option = []
			action = '\n        {\n'
			if 'error' in option:
				action = action + "             yyerrok;\n"
				action = action + "             PyObject* lasterr = PyObject_GetAttrString((PyObject*)py_parser, \"lasterror\");;\n"
			action = action + '          $$ = (*py_callback)(\n            py_parser, "%s", %s, %%s' % \
								(rule[0], idx) # note we're deferring the substitution of 'nterms' (last arg)
			args = []
			i = -1

			if nterms == 0:
				args.append('NULL')
			else:
				for i in range(nterms):
					if option[i] == '%prec':
						i = i - 1
						break # hack for rules using '%prec'
					o = option[i].replace('"', '\\"')
					if o == 'error':
						args.append('"%s", lasterr' % (o))
					else:
						args.append('"%s", $%d' % (o, i+1))
				print("args: ", args)

			# now, we have the correct terms count
			action = action % (i + 1)

			# assemble the full rule + action, add to list
			action = action + ",\n            "
			action = action + ",\n            ".join(args) + "\n            );\n"

			if 'error' in option:
				action = action + " PyObject_SetAttrString(py_parser, \"lasterror\", Py_None);\n"
				action = action + "             Py_DECREF(lasterr);\n"
				action = action + "             Py_INCREF(Py_None);\n"
				action = action + "             yyclearin;\n"

			else:
				action = action + "self.generate_exception_handler()"

			action = action + '        }\n'

			options.append(" ".join(option) + action)
			idx = idx + 1
		print("    | ".join(options) + "    ;\n\n")
	except:
		print("traceback.print_exc()")

print('\n\n%%\n\n')

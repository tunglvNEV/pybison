/* ======================================================================== */
/*	コベルコ建機様向け用　稼動機管理システム								*/
/*	ファイル名	：	itsh.l													*/
/*	説明		：	メール電文の字句解析									*/
/* ------------------------------------------------------------------------ */
/*	作成	SKCS	2009.02.01												*/
/*	更新																	*/
/*			KSC		2011.10.25	ミニ流用：国外／オーブコム２対応			*/
/*																			*/
/* ======================================================================== */

%x	COMMAND PARAM TEXTPARAM TEXTPARAM2
%{
#include <stdlib.h>
#include "itsh.tab.h"
#include "merit_bat.h"

#ifdef YYDEBUG
extern int yydebug;
#endif
extern int alloc_count;
static char body_line[BODY_LINE_MAX_LEN+1];
extern char cmd_line[BODY_LINE_MAX_LEN+1];

extern char *itc_strdup(const char *s);
extern CMD_POS_PARAM    G_CMD_POS_PARAM;

void to_command();

%}

lt_comma		(,)
lt_integer		([-\+]?[0-9]+)
lt_double		([-\+]?[0-9]+\.[0-9]+)
lt_pos_err		([-\+]?[X]+\.[X]+)
lt_okng			(OK|NG)
lt_on			(ON)
lt_off			(OF)
lt_ip_addr		([0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3})
lt_return		(\n)
lt_return_2		([\r\n])
lt_hex			([0-9A-Fa-f]+)
lt_xx			^([A-Za-z][0-9A-Za-z])
	/* 失敗 lt_xx			(\?!.\*(^(AR)))^(\?=([A-Za-z]{1}[0-9A-Za-z]{1}))[0-9A-Za-z]{2} */
lt_x1			^(([X]{1}[ABCDEFGHJKMNPQRSTUVWYZ]{1})|([Y]{1}[ABEFGHIJKQRSTUVWC]{1})|(HP))
lt_int2			([0-9]{2})
lt_int10		([0-9]{10})

	/* AEは衝突軽減系だが自己診断の形式とも一致する為、「lt_xx」はややこしい正規表現になっている。「\?」は「?」をエスケープしているだけ */

%%

<PARAM>{lt_comma}	return LT_COMMA;
<TEXTPARAM>{lt_comma}	return LT_COMMA;


<PARAM>{lt_int2} {
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)qlt_int2[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return (LT_INT2);
};

<PARAM>{lt_int2}/{lt_okng}{lt_return} {
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)qlt_int2[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return (LT_INT2);
};

<PARAM>{lt_int10} {
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)qlt_int10[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return (LT_INT10);
};

<PARAM>{lt_int10}/{lt_okng}{lt_return} {
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)qlt_int10[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return (LT_INT10);
};

<PARAM>{lt_integer} {
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)qlt_integer[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return (LT_INTEGER);
};

<PARAM>{lt_integer}/{lt_okng}{lt_return} {
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)qlt_integer[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return (LT_INTEGER);
};

<PARAM>{lt_hex}	{
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)qlt_hex[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return LT_HEX;
};

<PARAM>{lt_double} {
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)qlt_double[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return(LT_DOUBLE);
};

<PARAM>{lt_double}/{lt_okng}{lt_return} {
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)qlt_double[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return(LT_DOUBLE);
};

<PARAM>{lt_pos_err}	{
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)qlt_pos_err[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return LT_POS_ERR;
};

<PARAM>{lt_okng}	{
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)qlt_okng[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return LT_OKNG;
};

<PARAM>{lt_on}	{
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)qlt_on[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return LT_ON;
};

<PARAM>{lt_off}	{
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)qlt_off[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return LT_OFF;
};

<PARAM>{lt_ip_addr}	{
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)qlt_ip_addr[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return LT_IP_ADDR;
};

<TEXTPARAM>([^,\n]+)/{lt_return}	{
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)q([^,\\n]+)/(\\n)[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return LT_TEXT;
};

<TEXTPARAM2>([^\n]+)/{lt_return}	{
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)q([^\\n]+)/(\\n)[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return LT_TEXT;
};

<PARAM>([^,\n\r]+)	{
	yylval.strval = itc_strdup(yytext);
	#ifdef DEBUG
	printf("[%s][Line:%04d]q(^-^)q([^,\\n]+)[%s]\n",__FUNCTION__,__LINE__,yytext);
	#endif
	return LT_TEXT;
};

<COMMAND>(.+){lt_return}	{
	memset(body_line,0x00,sizeof(body_line));
	strncpy(body_line,yytext,strlen(yytext));
	REJECT;
};

<COMMAND>^[\t ]*{lt_return}		;

<COMMAND>P	{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/P\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_P;
};

<COMMAND>^H												{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/H\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_H;
};

<COMMAND>^SC												{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/SC\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_SC;
};

<COMMAND>^SA														{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/SA0\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_SA;
};

<COMMAND>^BT															{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/BT0\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_BT;
};

<COMMAND>^A														{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/A\n",__FUNCTION__,__LINE__);
	#endif

	return CMD_TOKEN_A;
};

<COMMAND>^EG															{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/EG\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_EG;
};

<COMMAND>^AM									{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/AM\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_AM;
};

<COMMAND>^AMOF									{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/AM\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_AMOF;
};

<COMMAND>^AMON									{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/AM\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_AMON;
};

<COMMAND>^CL		{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/CL\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_CL;
};
<COMMAND>^CM0															{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/CM0\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_CM0;
};
<COMMAND>^CM1															{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/CM0\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_CM1;
};
<COMMAND>^D0															{
	strcpy(cmd_line,body_line);
	BEGIN (TEXTPARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><TEXTPARAM>(= _ =)/D0\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_D0;
};
<COMMAND>^D1															{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/D1\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_D1;
};
<COMMAND>^D2															{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/D2\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_D2;
};
<COMMAND>^D3															{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/D3\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_D3;
};
<COMMAND>^M0														{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/M0\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_M0;
};
<COMMAND>^M1															{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/M1\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_M1;
};
<COMMAND>^M2															{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/M2\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_M2;
};
<COMMAND>^M3															{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/M3\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_M3;
};
<COMMAND>^M4															{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/M4\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_M4;
};
<COMMAND>^M5															{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/M5\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_M5;
};
<COMMAND>^M6															{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/M6\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_M6;
};
<COMMAND>^M7															{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/M7\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_M7;
};
<COMMAND>^M8															{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/M8\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_M8;
};

<COMMAND>^T																		{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/T\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_T;
};
<COMMAND>^P																		{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/P\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_P;
};
<COMMAND>^I																		{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/I\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_I;
};
<COMMAND>^R																	{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/R\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_R;
};
<COMMAND>^C																		{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/C\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_C;
};
<COMMAND>^N																		{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/N\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_N;
};
<COMMAND>^F																	{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/F\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_F;
};
<COMMAND>^W																		{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/W\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_W;
};
<COMMAND>^U																		{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/U\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_U;
};
<COMMAND>^J																	{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/J\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_J;
};
<COMMAND>^EC																		{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/EC\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_EC;
};
<COMMAND>^FC																		{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/FC\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_FC;
};
<COMMAND>^HC																		{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/HC\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_HC;
};
<COMMAND>^LC																		{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/LC\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_LC;
};
<COMMAND>^OV																		{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/OV\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_OV;
};
<COMMAND>^FT																		{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/FT\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_FT;
};
<COMMAND>^FS																		{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/FS\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_FS;
};

<COMMAND>^HS										{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/HS\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_HS;
};

<COMMAND>^HE										{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/HE\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_HE;
};

<COMMAND>^HF										{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/HF\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_HF;
};

<COMMAND>^HH										{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/HH\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_HH;
};

<COMMAND>^HL										{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/HL\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_HL;
};

<COMMAND>^AH:										{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/AH\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_AH;
};

<COMMAND>^PN										{
	strcpy(cmd_line,body_line);
	BEGIN (TEXTPARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><TEXTPARAM>(= _ =)/PN\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_PN;
};

<COMMAND>^VR										{
	strcpy(cmd_line,body_line);
	BEGIN (TEXTPARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><TEXTPARAM>(= _ =)/VR\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_VR;
};

<COMMAND>^SD										{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/SD\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_SD_1;
};

<COMMAND>^SD/([0-9]{4})(.*){lt_return}										{
	BEGIN (TEXTPARAM);
	#ifdef DEBUG
	/* SD(診断データ解析用(コマンド以降の解析はYで実施)) */
	printf("[%s][Line:%04d]-><TEXTPARAM>(= _ =)/SD(DIAGNOSIS)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_SD_2;
};

<COMMAND>^NP/{lt_integer},{lt_integer}{lt_return}				{
	/* 「NP」だけだと長さ優先で「自己診断の先読み」が勝つ。自己診断から「先読み」を外すと */
	/* 一文字系のコマンドが全て長さで負ける（T01010101は、T0と1010101でシンタックスエラー) */
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/NENPI\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_NENPI;
};

<COMMAND>^V				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/V\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_V;
};

<COMMAND>^EA				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/EA\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_EA;
};

<COMMAND>^PA				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/PA\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_PA;
};

<COMMAND>^PB				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/PB\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_PB;
};

<COMMAND>^PC				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/PC\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_PC;
};

<COMMAND>^UA				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/UA\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_UA;
};

<COMMAND>^UB				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/UB\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_UB;
};

<COMMAND>^SW				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/SW\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_SW;
};

<COMMAND>^ST				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/ST\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_ST;
};

<COMMAND>^MC				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/MC\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_MC;
};

<COMMAND>^MT				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/MT\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_MT;
};

<COMMAND>^DA				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/DA\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_DA;
};

<COMMAND>^SL				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/SL\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_SL;
};

<COMMAND>^TD				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/TD\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_TD;
};

	/* 衝突軽減機能切り替え情報(AE) */
<COMMAND>^AE/{lt_integer}{lt_comma}{lt_integer}{lt_return}				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/AE\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_AE;
};

<COMMAND>^AE				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/AE\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_AE;
};

	/* 衝突軽減レポート(AR) */
<COMMAND>^AR/{lt_integer}{lt_comma}{lt_integer}{lt_return}				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/AR\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_AR;
};

	/* 衝突軽減レポート(AR) */
<COMMAND>^AR				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/AR\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_AR;
};

	/* 再生診断(RR) */
<COMMAND>^RR/{lt_integer}{lt_comma}{lt_integer}{lt_return}				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/RR\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_RR;
};

	/* 再生診断(RR) */
<COMMAND>^RR				{
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/RR\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_RR;
};

	/* SSID書込み(SSID) */
<COMMAND>^SSID				{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/SSID\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_SSID;
};

	/* K-LOAD作業データ(KL) */
<COMMAND>^KL				{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/KL\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_KL;
};


	/* 状態観察（１） */
<COMMAND>{lt_x1}/{lt_integer}{lt_return}			{

	/* 位置情報を持たない場合はREJECT */
	if(0x00 == G_CMD_POS_PARAM.cmd_all[0]){
		#ifdef DEBUG
		printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 1(REJECT))\n",__FUNCTION__,__LINE__);
		#endif
		REJECT;
	}

	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 1)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_X1;
}

	/* 状態観察（４） */
<COMMAND>{lt_x1}/{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_return}			{

	/* 位置情報を持たない場合はREJECT */
	if(0x00 == G_CMD_POS_PARAM.cmd_all[0]){
		#ifdef DEBUG
		printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 4(REJECT))\n",__FUNCTION__,__LINE__);
		#endif
		REJECT;
	}

	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 4)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_X1;
}

	/* 状態観察（３） */
<COMMAND>{lt_x1}/{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_return}			{

	/* 位置情報を持たない場合はREJECT */
	if(0x00 == G_CMD_POS_PARAM.cmd_all[0]){
		#ifdef DEBUG
		printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 3(REJECT))\n",__FUNCTION__,__LINE__);
		#endif
		REJECT;
	}

	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 3)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_X1;
}


	/* 状態観察（５） */
<COMMAND>{lt_x1}/{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_return}			{

	/* 位置情報を持たない場合はREJECT */
	if(0x00 == G_CMD_POS_PARAM.cmd_all[0]){
		#ifdef DEBUG
		printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 5(REJECT))\n",__FUNCTION__,__LINE__);
		#endif
		REJECT;
	}

	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 5)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_X1;
}

	/* 状態観察（１２） */
<COMMAND>{lt_x1}/{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_return}			{

	/* 位置情報を持たない場合はREJECT */
	if(0x00 == G_CMD_POS_PARAM.cmd_all[0]){
		#ifdef DEBUG
		printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 12(REJECT))\n",__FUNCTION__,__LINE__);
		#endif
		REJECT;
	}

	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 12)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_X1;
}

	/* 状態観察（１３） */
<COMMAND>{lt_x1}/{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_return}			{

	/* 位置情報を持たない場合はREJECT */
	if(0x00 == G_CMD_POS_PARAM.cmd_all[0]){
		#ifdef DEBUG
		printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 13(REJECT))\n",__FUNCTION__,__LINE__);
		#endif
		REJECT;
	}

	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 13)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_X1;
}

	/* 状態観察（２６） */
<COMMAND>{lt_x1}/{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_return}			{

	/* 位置情報を持たない場合はREJECT */
	if(0x00 == G_CMD_POS_PARAM.cmd_all[0]){
		#ifdef DEBUG
		printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 26(REJECT))\n",__FUNCTION__,__LINE__);
		#endif
		REJECT;
	}

	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 26)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_X1;
}

	/* 状態観察（２） */
<COMMAND>{lt_x1}/{lt_integer}{lt_comma}{lt_integer}{lt_return}			{

	/* 位置情報を持たない場合はREJECT */
	if(0x00 == G_CMD_POS_PARAM.cmd_all[0]){
		#ifdef DEBUG
		printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 2(REJECT))\n",__FUNCTION__,__LINE__);
		#endif
		REJECT;
	}
	
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 2)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_X1;
}

	/* 状態観察（１７） */
<COMMAND>{lt_x1}/{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_return}			{

	/* 位置情報を持たない場合はREJECT */
	if(0x00 == G_CMD_POS_PARAM.cmd_all[0]){
		#ifdef DEBUG
		printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 17(REJECT))\n",__FUNCTION__,__LINE__);
		#endif
		REJECT;
	}

	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 17)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_X1;
}

	/* 状態観察（１１） */
<COMMAND>{lt_x1}/{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_return}			{

	/* 位置情報を持たない場合はREJECT */
	if(0x00 == G_CMD_POS_PARAM.cmd_all[0]){
		#ifdef DEBUG
		printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 11(REJECT))\n",__FUNCTION__,__LINE__);
		#endif
		REJECT;
	}

	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 11)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_X1;
}


	/* 状態観察（６） */
<COMMAND>{lt_x1}/{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_return}			{

	/* 位置情報を持たない場合はREJECT */
	if(0x00 == G_CMD_POS_PARAM.cmd_all[0]){
		#ifdef DEBUG
		printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 6(REJECT))\n",__FUNCTION__,__LINE__);
		#endif
		REJECT;
	}

	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 6)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_X1;
}

	/* 状態観察（８） */
<COMMAND>{lt_x1}/{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_comma}{lt_integer}{lt_return}			{

	/* 位置情報を持たない場合はREJECT */
	if(0x00 == G_CMD_POS_PARAM.cmd_all[0]){
		#ifdef DEBUG
		printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 8(REJECT))\n",__FUNCTION__,__LINE__);
		#endif
		REJECT;
	}

	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/X1(HOZEN 8)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_X1;
}


<COMMAND>^HA				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/HA\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_HA;
};

<COMMAND>^LK				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/LK\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_LK;
};

<COMMAND>^YD				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/YD\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_YD;
};

<COMMAND>^OT				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/OT\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_OT;
};

<COMMAND>^M/{lt_integer}{lt_return}				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	/* Mだけだと続く数値が０～８等だと通信量確認応答のキーワードに重複する。 */
	/* 通信量確認応答は「M0,12345」なのでそれらを除外する為、先読み。 */
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/M\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_M;
};

<COMMAND>^JH				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/JH\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_JH;
};

<COMMAND>^JS				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/JS\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_JS;
};

<COMMAND>^JE				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/JE\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_JE;
};

<COMMAND>^AB				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/AB\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_AB;
};

<COMMAND>^SS				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/SS\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_SS;
};

<COMMAND>^SR				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/SR\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_SR;
};

<COMMAND>^SG				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/SG\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_SG;
};

<COMMAND>^SU				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/SU\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_SU;
};

<COMMAND>^DG				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/DG\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_DG;
};

<COMMAND>^DU				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/DU\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_DU;
};

<COMMAND>^DC				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/DC\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_DC;
};

<COMMAND>^DR				{
	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);

	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/DR\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_DR;
};

<COMMAND>^\*\*	{
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/Asterisk1\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_ASTRSK1;
};

<COMMAND>^\*	{
	strcpy(cmd_line,body_line);
	BEGIN (TEXTPARAM2);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><TEXTPARAM2>(= _ =)/Asterisk2\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_ASTRSK2;
};

<COMMAND>^#	{
	strcpy(cmd_line,body_line);
	BEGIN (TEXTPARAM2);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><TEXTPARAM2>(= _ =)/NUMSIGN\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_NUMSIGN;
};

	/* (2015.12.15神田)FDで始まる行 */
<COMMAND>^FD/([^\r\n]+){lt_return}	{
	yylval.strval = itc_strdup(yytext);

	strcpy(cmd_line,body_line);
	BEGIN (TEXTPARAM2);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><TEXTPARAM2>(= _ =)/FD\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_FD;
};

	/* (2015.12.15神田)FRで始まる行 */
<COMMAND>^FR/([^\r\n]+){lt_return}	{
	yylval.strval = itc_strdup(yytext);

	strcpy(cmd_line,body_line);
	BEGIN (TEXTPARAM2);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><TEXTPARAM2>(= _ =)/FR\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_FR;
};

	/* (2015.12.15神田)FRで始まる行 */
<COMMAND>^FQ/([^\r\n]+){lt_return}	{
	yylval.strval = itc_strdup(yytext);

	strcpy(cmd_line,body_line);
	BEGIN (TEXTPARAM2);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><TEXTPARAM2>(= _ =)/FR\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_FQ;
};


	/* 故障診断(FD,FR)と同様に健康診断もコーディングしたかったが
		既に「HD」の警報が存在する為、「HDOK」は「HD/(TEXTPARAM2)」とせずに
		「HDOK」としてフルフルで指定する。定義順を変えるのも一つの手段だが・・・
		それは・・・最後の手段とする。 
		※ちなみに警報HDはエラーコード有りの警報
	*/

	/* (2016.01.27神田)HDで始まる行 */
<COMMAND>^HD/{lt_okng}{lt_return}	{
	yylval.strval = itc_strdup(yytext);

	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><TEXTPARAM2>(= _ =)/HD\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_HD;
};

	/* (2016.01.27神田)HPで始まる行 */
<COMMAND>^HP/([^\r\n]+){lt_return}	{
	yylval.strval = itc_strdup(yytext);

	strcpy(cmd_line,body_line);
	BEGIN (TEXTPARAM2);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><TEXTPARAM2>(= _ =)/HP\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_HP;
};

	/* (2016.01.27神田)HQで始まる行 */
<COMMAND>^HQ/([^\r\n]+){lt_return}	{
	yylval.strval = itc_strdup(yytext);

	strcpy(cmd_line,body_line);
	BEGIN (TEXTPARAM2);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><TEXTPARAM2>(= _ =)/HQ\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_HQ;
};

	/* (2018.07.27 神田)VE(ソフト情報＠天王山対応) */
<COMMAND>^VE/([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_return}	{
	yylval.strval = itc_strdup(yytext);

	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><TEXTPARAM2>(= _ =)/VE\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_VE;
};

	/* (2018.07.27 神田)TC(メンテナンス残時間＠天王山対応) */
<COMMAND>^TC/([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_return}	{
	yylval.strval = itc_strdup(yytext);

	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><TEXTPARAM2>(= _ =)/TC(12)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_TC;
};

	/* (2018.07.27 神田)TC(メンテナンス残時間＠天王山対応) */
<COMMAND>^TC/([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_comma}([^\r\n,]+){lt_return}	{
	yylval.strval = itc_strdup(yytext);

	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><TEXTPARAM2>(= _ =)/TC(10)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_TC;
};


	/* (2011.06.07神田)
		警報系は、全てCMD_TOKEN_XXで取り扱う。特別な処理が必要な警報があればここに記述すればよいが、無いはず
		追加する際は、CMD_TOKEN_XXと同精度の先読みをさせないとCMD_TOKEN_XXが優先されるので注意。
	   (2011.06.10神田)
		どうやらRT応答に付随する警報（のみかは不明だが）には、日付時刻が付かないようだ。
		RT応答なので、POSに日付時刻あるから省略したのか？でもそれだと警報発生のタイミングではなく、
		RT応答の時間に発生したことになるのか？

		(2015.12.15神田)
		上で書いている「CMD_TOKEN_XXと同精度の先読みをさせないとCMD_TOKEN_XXが優先されるので注意。」に
		まさに合致した形式で来る電文が追加された[FR0,1512131500]を含む複数行を対応する事となった。
		今回はFR及び、FDは開発時点で仕様が流動的である為、共に先読みをして逃げる事とする。
		今後の為に実現性は未検証だが・・・CMD_TOKEN_XXは単一行なのだか・・・あ・・・「_CMD_LINES_XX」がある・・・
		旧型機のRTに警報が付くパターンの対応の為？なくならないかな・・・
		とにかくこの点は本当に注意が必要。
		
		(2015.12.15神田)
		あまり意識してなかったが行頭からのコメントはコンパイルが通らないようだ。
	*/


<PARAM>{lt_return}	{
	#ifdef DEBUG
	printf("[%s][Line:%04d](PARAM)-(LT_RETURN)\n",__FUNCTION__,__LINE__);
	#endif
	return LT_RETURN;
};

<PARAM>{lt_return_2}	{
	#ifdef DEBUG
	printf("[%s][Line:%04d](PARAM)-(LT_RETURN_2)\n",__FUNCTION__,__LINE__);
	#endif
	return LT_RETURN_2;
};


<TEXTPARAM>{lt_return}	{
	#ifdef DEBUG
	printf("[%s][Line:%04d](TEXTPARAM)-(LT_RETURN)\n",__FUNCTION__,__LINE__);
	#endif
	return LT_RETURN;
};

<TEXTPARAM2>{lt_return}	{
	#ifdef DEBUG
	printf("[%s][Line:%04d](TEXTPARAM2)-(LT_RETURN)\n",__FUNCTION__,__LINE__);
	#endif
	return LT_RETURN;
};


<INITIAL>(.+){lt_return}	{
	#ifdef DEBUG
	printf("[%s][Line:%04d](...mail head...)\n",__FUNCTION__,__LINE__);
	#endif
	return LT_HEADER_ONE_LINE;
};

<INITIAL>{lt_return}	{
	to_command();
	return LT_RETURN_HEADER;
}

<*><<EOF>>	{
	_eof();
	yyterminate();
}

<COMMAND>{lt_xx}/([1|0|\*]),{lt_integer}{lt_return}			{

	if(0x00 != G_CMD_POS_PARAM.cmd_all[0]){
		#ifdef DEBUG
		/* (自己診断候補) */
		printf("[%s][Line:%04d]-><PARAM>(= _ =)/XX(SELF-01)\n",__FUNCTION__,__LINE__);
		#endif
		REJECT;
	}

	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	
	#ifdef DEBUG
	/* (自己診断候補) */
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/XX(SELF-02)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_XX;
}

<COMMAND>{lt_xx}/([1|0|\*]),([^,\n]+),{lt_int10}{lt_return}			{

	if(0x00 != G_CMD_POS_PARAM.cmd_all[0]){
		#ifdef DEBUG
		/* XX_V7(自己診断候補) */
		printf("[%s][Line:%04d]-><PARAM>(= _ =)/XX_V7(SELF-03)\n",__FUNCTION__,__LINE__);
		#endif
		REJECT;
	}

	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	
	#ifdef DEBUG
	/* XX_V7(自己診断候補) */
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/XX_V7(SELF-04)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_XX;
}


<COMMAND>{lt_xx}/([1|0|\*]),([^,\n]+),{lt_int10},([^,\n]+){lt_return}			{

	if(0x00 != G_CMD_POS_PARAM.cmd_all[0]){
		#ifdef DEBUG
		/* XX_V7(自己診断候補) */
		printf("[%s][Line:%04d]-><PARAM>(= _ =)/XX_V7(SELF-05)\n",__FUNCTION__,__LINE__);
		#endif
		REJECT;
	}

	yylval.strval = itc_strdup(yytext);
	
	strcpy(cmd_line,body_line);
	BEGIN (PARAM);
	
	#ifdef DEBUG
	/* XX_V7(自己診断候補) */
	printf("[%s][Line:%04d]-><PARAM>(= _ =)/XX_V7(SELF-06)\n",__FUNCTION__,__LINE__);
	#endif
	return CMD_TOKEN_XX;
}
<*>(.)	{
	/* 上記のルールでは解析できなかったの文字が出現した場合 */
	/* ※yaccの警告で未使用(Terminals which are not used)とでるが */
	/*   正常メール形式の後方にゴミが付いている場合に、syntax errorとする。*/
	/*   コレが無い場合、読み捨てられて正常扱いとなってしまう。 */
	#ifdef DEBUG
	printf("[%s][Line:%04d]TOKEN_ERROR\n",__FUNCTION__,__LINE__);
	#endif
	return TOKEN_ERROR;
};


%%

int yywrap(void)
{
	#ifdef YYDEBUG
	yydebug = 1;
	#endif
	BEGIN (INITIAL);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><INITIAL>\n",__FUNCTION__,__LINE__);
	#endif
	return 1;
}

void to_command()
{
	BEGIN (COMMAND);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><COMMAND> **************************************** COMMAND\n",__FUNCTION__,__LINE__);
	#endif
}

void next_cmd()
{
	to_command();
	#ifdef DEBUG
	printf("[%s][Line:%04d]<< 1 Line = 1 command OK>>\n",__FUNCTION__,__LINE__);
	printf("\n");
	#endif
}

void setInitial_mode()
{
	BEGIN (INITIAL);
	#ifdef DEBUG
	printf("[%s][Line:%04d]-><INITIAL> **************************************** INITIAL\n",__FUNCTION__,__LINE__);
	#endif
}


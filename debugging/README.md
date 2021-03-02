# Debugging pybison

This is a short introduction in debugging python scripts with gdb.

## Install requirements

Install `gdb`, `pyenv` and `pyenv-virtualenv`.

### Creating a python debug environment

A debug python version is needed, we use pyenv to install it.
```shell
pyenv install -g 3.9.1
```
Here, we installed python version `3.9.1` with debug symbols (`-g`). Feel free to choose any other version.

Make sure the installed pyenv python version is accessible, run the following commands:
```shell
eval "$(pyenv init -)"
eval "$(pyenv virtualenv-init -)"
```

Create a virtualenv using the installed debug version:
```shell
pyenv virtualenv 3.9.1-debug pybison-d-3.9.1
```
where `3.9.1-debug` is the installed python version with debug symbols (check with `pyenv versions` what is actually available)
and `pybison-d-3.9.1` is an arbitrary name for our environment.

Now `pyenv virtualenvs` lists all the existing environments.

Finally, we activate the created virtualenv
```shell
pyenv activate pybison-d-3.9.1
```

(Note: Later on the virtualenv can be deactivated in the same fashion by executing `pyenv deactivate`)

### Setting up gdb for python

We will extend gdb with some python-aware behavior and python-specific commands by adding the python extension to gdb.

First, the actual python version is needed, against gdb is build.
To get the python version used by gdb run `gdb --command=checkpython.gdb -ex quit`.

The very last line will print the python version used:
```shell
sys.version_info(major=3, minor=9, micro=2, releaselevel='final', serial=0)
```
which shows that the major/minor version is `3.9`
Thus, we need to download `https://github.com/python/cpython/blob/3.9/Tools/gdb/libpython.py` and save it in ` ~/.config/gdb/libpython.py`.
(Make sure to choose the right branch/python version if you don't work with `3.9`)

Copy the local `.gdbinit` file to `~/.gdbinit`, or integrate it in your current setup.


### Setting up pybison

Compile pybison with debug flags
```shell
CFLAGS="-O0 -g" CXXFLAGS="-O0 -g" python setup.py install
```

## Debug

Set debug flags for this session:
```shell
export CFLAGS="-O0 -g"; export CXXFLAGS="-O0 -g"
```

To debug a python script run the following:
__WARNING__ pyenv install/starts a bash script, so do
```shell
gdb -ex r --args bash python <programname>.py <arguments>
``` 

Happy debugging!

## Notes

To clean the installed pybison package
```
python setup.py clean --all
```
Additionally, every temporary file must be deleted as well,
e.g. all dynamic libraries of parsers and compiled grammar / lexer files.

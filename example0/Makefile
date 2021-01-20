# Module name
MOD = chelpers

# You might want to invoke make with "PYTHON=python3 make test"
PYTHON ?= python

# Source files
SOURCE = $(MOD).c
PYLIB = $(MOD).so

default: test

test: $(PYLIB)
	$(PYTHON) test.py

$(PYLIB): setup.py $(SOURCE)
	$(PYTHON) setup.py build --build-platlib=./ --build-temp=./

clean:
	-rm *.o
	-rm $(MOD)*.so

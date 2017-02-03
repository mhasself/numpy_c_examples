# Module name
MOD = chelpers

# Source files
SOURCE = $(MOD).c
PYLIB = $(MOD).so

default: $(PYLIB)

$(PYLIB): setup.py $(SOURCE)
	python setup.py build --build-platlib=./ --build-temp=./

clean:
	-rm *.o
	-rm $(PYLIB)

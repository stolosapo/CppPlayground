#
# TODO: Move `libmongoclient.a` to /usr/local/lib so this can work on production servers
#
 
CC := g++ # This is the main compiler
# CC := clang --analyze # and comment out the linker last line for sanity
SRCDIR := src
TESTDIR := test
BUILDDIR := build
CLEANDIR := build/*.o
CLEANSUBDIR := build/**/*.o

TARGET := bin/runner
TESTTARGET := bin/tester
TICKETTARGET := bin/ticket
 
SRCEXT := cpp

SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

TESTSOURCES := $(shell find $(TESTDIR) -name *.$(SRCEXT))
TESTOBJECTS := $(patsubst $(TESTDIR)/%,$(BUILDDIR)/%,$(TESTSOURCES:.$(SRCEXT)=.o))

CFLAGS := -g # -Wall
# LIB := -pthread -lmongoclient -L lib -lboost_thread-mt -lboost_filesystem-mt -lboost_system-mt
# LIB := -pthread -L lib -lboost_thread-mt -lboost_filesystem-mt -lboost_system-mt
LIB := -pthread -L lib
INC := -I include

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

# @echo " $(RM) -r $(CLEANDIR) $(CLEANSUBDIR) $(TARGET) $(TESTTARGET) $(TICKETTARGET) "; $(RM) -r $(CLEANDIR) $(CLEANSUBDIR) $(TARGET) $(TESTTARGET) $(TICKETTARGET)
clean:
	@echo " Cleaning..."; 
	$(shell find $(BUILDDIR) -name *.o | xargs $(RM) -r $TARGET $TESTTARGET $TICKETTARGET)

# Tests
$(BUILDDIR)/%.o: $(TESTDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

tester: $(TESTOBJECTS)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TESTTARGET) $(LIB)"; $(CC) $^ -o $(TESTTARGET) $(LIB)

# Spikes
ticket:
	$(CC) $(CFLAGS) spikes/ticket.cpp $(INC) $(LIB) -o $(TICKETTARGET)

.PHONY: clean
#
# TODO: Move `libmongoclient.a` to /usr/local/lib so this can work on production servers
#
 
CC := g++ # This is the main compiler
# CC := clang --analyze # and comment out the linker last line for sanity
SRCDIR := src
BUILDDIR := build
CLEANDIR := build/*.o
CLEANSUBDIR := build/**/*.o

TARGET := bin/runner
TESTTARGET := bin/tester
TICKETTARGET := bin/ticket
MISCTARGET := bin/misc
 
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
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

clean:
	@echo " Cleaning..."; 
	@echo " $(RM) -r $(CLEANDIR) $(CLEANSUBDIR) $(TARGET) $(TESTTARGET) $(TICKETTARGET) $(MISCTARGET)"; $(RM) -r $(CLEANDIR) $(CLEANSUBDIR) $(TARGET) $(TESTTARGET) $(TICKETTARGET) $(MISCTARGET)

# Tests
tester:
	$(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o $(TESTTARGET)

# Spikes
ticket:
	$(CC) $(CFLAGS) spikes/ticket.cpp $(INC) $(LIB) -o $(TICKETTARGET)

# Other executables
misc:
	$(CC) $(CFLAGS) misc/app.cpp $(INC) $(LIB) -o $(MISCTARGET)

.PHONY: clean misc
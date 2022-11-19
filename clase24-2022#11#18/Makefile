slib=libinfo1sock.a
SO=libinfo1sock.so
SONAME=$(SO).1
VER=0
REL=1
dlib=$(SONAME).$(VER).$(REL)
CC=gcc
SCFLAGS=-c -g -Wall
DCFLAGS=-c -fPIC -g -Wall
LDFLAGS=-shared -Wl,-soname,$(SONAME) -lc -Wall
OBJS=sock-lib.o
SHAREDPATH=./shared/
INSTALL_PATH=~/mylibs/
INSTALL_INC_PATH=~/myincludes/
empty:
	@echo "Error"
	@echo "Invocar como make estática | dinámica | all"

all: estática dinámica

estática: $(slib)
$(slib):$(OBJS)
	ar rcs $@ $<   
%.o:%.c
	$(CC) $(SCFLAGS) -o$@ $<
dinámica: $(dlib)
$(dlib):$(OBJS)
	@mkdir $(SHAREDPATH) 2>/dev/null
	$(CC) $(LDFLAGS) -o$(SHAREDPATH)$@ $<
	sudo ldconfig -n $(SHAREDPATH)
	ln -sfvn $(SONAME) $(SHAREDPATH)libsock.so
%.o:%.c
	$(CC) $(DCFLAGS) -o$@ $<
clean:
	rm -f *.o *.a
	sudo rm -f $(slib) 
	rm -r $(SHAREDPATH)
install:
	cp $(slib) $(INSTALL_PATH)
	cp *.h $(INSTALL_INC_PATH)
	cp $(SHAREDPATH)$(dlib) $(INSTALL_PATH)
	sudo ldconfig -n $(INSTALL_PATH)
	ln -sfvn $(SONAME) $(INSTALL_PATH)$(SO)

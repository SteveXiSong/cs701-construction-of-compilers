DEBUG = ../../Debug/lib
OBJS = printCode.o  loopInv.o

$(DEBUG)/P3.so: $(OBJS)
	mkdir -p $(DEBUG)
	g++ $(OBJS) -shared -o $@ -fPIC

%.o: %.cpp 
	g++ -c -fno-rtti `llvm-config --cppflags` -g -fPIC $< -o $@

clean:
	rm -f $(DEBUG)/P3.so $(OBJS)

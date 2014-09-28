lib_name=			hexlog
c_sample_name=		sample
cxx_sample_name=	sample_plus

lib_objects=    	hexlog.o 										\
					hexlog_plus.o

c_sample_objects= 	sample.o
cxx_sample_objects= sample_plus.o

all:				link

link:				link_lib link_c_sample link_cxx_sample

link_lib:			$(lib_objects)
		ar rcs libhexlog.a $(lib_objects)

link_c_sample: 		$(c_sample_objects)
		$(CC) $(LDFLAGS) $(c_sample_objects) -L./ -lhexlog -o $(c_sample_name)

link_cxx_sample:	$(cxx_sample_objects)
		$(CXX) $(LDFLAGS) $(cxx_sample_objects) -L./ -lhexlog -o $(cxx_sample_name)

%.o: 				%.c
		$(CC) $(CFLAGS) $(CPPFLAGS) $(CXXFLAGS) -std=c99 -O2 -c $<

%.o: 				%.cpp
		$(CXX) $(CFLAGS) $(CPPFLAGS) $(CXXFLAGS) -O2 -c $<

install:			link
		cp libhexlog.a /usr/local/lib
		cp hexlog.h /usr/local/include/hexlog/
		cp hexlog_plus.hpp /usr/local/include/hexlog/

.PHONY : 			clean

clean:
		rm -f $(lib_objects) 										\
			$(c_sample_objects) 									\
			$(cxx_sample_objects) 									\
			lib$(lib_name).a 										\
			$(cxx_sample_name)										\
			$(c_sample_name)

lib_name=		hexlog
sample_name=	sample

lib_objects=    hexlog.o \
				hexlog_plus.o

sample_objects= main.o

all:			link

link:			link_lib link_sample

link_lib:		$(lib_objects)
		ar rcs libhexlog.a $(lib_objects)

link_sample: 	$(sample_objects)
		$(CXX) $(LDFLAGS) $(sample_objects) -L./ -lhexlog -o sample

%.o: 			%.cpp %.c
		$(CXX) $(CFLAGS) $(CPPFLAGS) $(CXXFLAGS) -O2 -c $<

install:		link
		cp libhexlog.a /usr/local/lib
		cp hexlog.h /usr/local/include/hexlog/
		cp hexlog_plus.hpp /usr/local/include/hexlog/

.PHONY : 		clean

clean:
		rm -f $(lib_objects) 	\
			$(sample_objects) 	\
			lib$(lib_name).a 	\
			$(sample_name)

SRCDIR   := src
BUILDDIR := build
LDFLAGS  := -pthread
CXXFLAGS := -pedantic-errors -Wall -Wextra -Werror -std=c++11 -I include


all: CreateSemSmokers DeleteSemSmokers Smoker Agent

VPATH=src

CreateSemSmokers: CreateSemSmokers.o names.o sync.o
	$(CXX) -o $@ $(LDFLAGS) $^

CreateSemSmokers.o: CreateSemSmokers.cpp ../include/names.h ../include/sync.h

names.o: names.cpp ../include/names.h

sync.o: sync.cpp ../include/sync.h

DeleteSemSmokers: DeleteSemSmokers.o names.o sync.o
	$(CXX) -o $@ $(LDFLAGS) $^

DeleteSemSmokers.o: DeleteSemSmokers.cpp ../include/names.h ../include/sync.h

Smoker: Smoker.o sync.o
	$(CXX) -o $@ $(LDFLAGS) $^

Smoker.o: Smoker.cpp ../include/sync.h

Agent: Agent.o names.o sync.o
	$(CXX) -o $@ $(LDFLAGS) $^

Agent.o: Agent.cpp ../include/names.h ../include/sync.h

clean:
	rm -f src/*.o src/*.*~ include/*.*~ *~

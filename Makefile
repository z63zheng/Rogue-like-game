CXX=g++-5
CXXFLAGS=-std=c++14 -Wall -Werror -MMD -g
OBJECTS=treasure.o potion.o observer.o DamageVisitor.o Defend.o EnemyConcrete.o PlayerConcrete.o character2.o grid.o subject.o tile.o PotionDecorator.o PotionConcrete.o main.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=cc3k

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm *.d *.o cc3k
.PHONY: clean



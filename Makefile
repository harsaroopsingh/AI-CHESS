CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -MMD -Werror=vla -Wno-error
#CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
EXEC = chess
OBJECTS = main.o bishop.o castle.o king.o queen.o nopiece.o pawn.o knight.o tile.o player.o human.o computer.o chessboard.o piece.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}


# define the C compiler to use
CC = g++

# define any compile-time flags
CFLAGS = -Wall -static

# define any directories containing header files other than /usr/include
INCLUDES = -I./src -I./src/Enums -I./src/Tetromino -I./src/Utils

# define the C source files
SRCS = 	./src/main.cpp \
		./src/ProgramManager.cpp \
		./src/Utils/BestFitObject.cpp \
		./src/Utils/Coordinate.cpp \
		./src/Utils/PrintHandler.cpp \
		./src/Utils/Util.cpp \
		./src/Tetromino/Tetromino.cpp \
		./src/Tetromino/TetrominoFactory.cpp \
		./src/Tetromino/Tetro_I.cpp \
		./src/Tetromino/Tetro_J.cpp \
		./src/Tetromino/Tetro_L.cpp \
		./src/Tetromino/Tetro_O.cpp \
		./src/Tetromino/Tetro_S.cpp \
		./src/Tetromino/Tetro_T.cpp \
		./src/Tetromino/Tetro_Z.cpp

OBJS = 	./main.o \
		./ProgramManager.o \
		./BestFitObject.o \
		./Coordinate.o \
		./PrintHandler.o \
		./Util.o \
		./Tetromino.o \
		./TetrominoFactory.o \
		./Tetro_I.o \
		./Tetro_L.o \
		./Tetro_J.o \
		./Tetro_O.o \
		./Tetro_S.o \
		./Tetro_T.o \
		./Tetro_Z.o

#MAIN = HW1-TETRIS

.PHONY: depend

all:
	mkdir -p bin
	mkdir -p build-Makefile
	${CC} ${CFLAGS} ${INCLUDES} -c ${SRCS}
	${CC} ${CFLAGS} ${INCLUDES} -o HW1-TETRIS ${MAIN} ${OBJS}
	cp *.o ./build-Makefile
	cp HW1-TETRIS ./bin
	rm *.o
	rm HW1-TETRIS

${MAIN}:
	${CC} ${CFLAGS} ${INCLUDES} -o HW1-TETRIS ${MAIN} ${OBJS}

%.o: %.cpp ${INCLUDES}
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

clean:
	rm -r bin
	rm -r build-Makefile

depend: ${SRCS}
	makedepend ${INCLUDES} $^
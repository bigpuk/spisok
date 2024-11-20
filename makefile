
DED_FLAGS=-Wall -Wextra -Weffc++ -Wcast-align -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal 	\
-Wformat-security -Wformat=2 -Wignored-qualifiers -Winit-self -Winline -Wlogical-op -Wmain -Wmissing-declarations 		\
-Wno-missing-field-initializers -Wmissing-include-dirs -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith 			\
-Wredundant-decls -Wshadow -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wswitch-default	\
-Wswitch-enum -Wtype-limits -Wundef -Wunreachable-code -Wwrite-strings -fexceptions -g -pipe -D_DEBUG 					\
-D_EJUDGE_CLIENT_SIDE -D_EJC

INCLUDE_FLAGS=-I./include

FILES=main.cpp sp_ctor.cpp sp_in.cpp sp_pop.cpp sp_del.cpp sp_insert.cpp sp_dtor.cpp sp_dump.cpp prev_dump.cpp next_dump.cpp
FILE_OBJECTS=$(addprefix build/, $(patsubst %.cpp, %.o, $(FILES)))

COMPILE_NAMES=$(patsubst %.cpp, , $(FILES))

EXE_NAME=SPISOK

all: $(EXE_NAME)

$(EXE_NAME): $(FILE_OBJECTS)
	@g++ $^ $(DED_FLAGS) -o $(EXE_NAME)
	@echo "[LD] Linking"
# TODO var

build/%.o: src/%.cpp
	@g++ -c $^ $(DED_FLAGS) $(INCLUDE_FLAGS) -o $@
	@echo "[CXX]"

clean:
	rm -rf build/* *.exe
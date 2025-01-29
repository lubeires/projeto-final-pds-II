# Compilador e flags
CXX = g++
CXXFLAGS = -I./include -std=c++17 -Wall -Wextra

# Diretórios
SRC_DIR = ./src
OBJ_DIR = ./obj
BUILD_DIR = ./build
INCLUDE_DIR = ./include
TEST_DIR = ./tests
TEST_BUILD_DIR = $(BUILD_DIR)/tests

# Arquivos fonte
SRCS = $(filter-out $(SRC_DIR)/main.cpp, $(wildcard $(SRC_DIR)/*.cpp)) # Exclui o main.cpp
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)

# Objetos correspondentes
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
MAIN_OBJ = $(OBJ_DIR)/main.o
TEST_OBJS = $(OBJ_DIR)/tests.a

# Executáveis
EXEC = $(BUILD_DIR)/sistema
TEST_EXECS = $(patsubst $(TEST_DIR)/%.cpp, $(TEST_BUILD_DIR)/%, $(TEST_SRCS))

# Regra padrão
all: $(EXEC) tests

# Executável final
$(EXEC): $(OBJS) $(MAIN_OBJ)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Arquivos .o do código principal
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Biblioteca estática para testes
$(TEST_OBJS): $(OBJS)
	@mkdir -p $(OBJ_DIR)
	ar rcs $@ $^

# Compilação de testes
tests: $(TEST_EXECS)

$(TEST_BUILD_DIR)/%: $(TEST_DIR)/%.cpp $(TEST_OBJS)
	@mkdir -p $(TEST_BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $< $(TEST_OBJS)

# Limpeza dos arquivos gerados
clean:
	rm -rf $(OBJ_DIR) $(BUILD_DIR)

# Regra de "phony" para evitar conflito com arquivos reais
.PHONY: all clean tests

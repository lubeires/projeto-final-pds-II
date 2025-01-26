# Compilador e flags
CXX = g++
CXXFLAGS = -I./include -std=c++17 -Wall -Wextra

# Diretórios
SRC_DIR = ./src
BUILD_DIR = ./build
INCLUDE_DIR = ./include

# Arquivos fonte
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
# Objetos correspondentes
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Executável final
EXEC = $(BUILD_DIR)/sistema

# Regra padrão (primeira a ser chamada)
all: $(EXEC)

# Regra para criar o executável final
$(EXEC): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regra para criar os arquivos .o a partir dos .cpp
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza dos arquivos gerados
clean:
	rm -rf $(BUILD_DIR)

# Regra de "phony" para evitar conflito com arquivos reais
.PHONY: all clean

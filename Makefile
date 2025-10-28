# Назва виконуваного файлу
TARGET = app

# Компилятор і прапори
CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude

# Папка для об'єктних файлів
OBJDIR = build

# Всі .cpp файли
SRC_ROOT = $(wildcard src/*.cpp)
SRC_MODULE = $(wildcard src/module/*.cpp)
SRC = $(SRC_ROOT) $(SRC_MODULE)

# Імена .o файлів у build/ (без підпапок)
OBJ = $(addprefix $(OBJDIR)/,$(notdir $(SRC:.cpp=.o)))

# Основна ціль
all: $(OBJDIR) $(TARGET)

# Створення папки build
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Лінкування
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Правила компіляції .cpp -> .o
$(OBJDIR)/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/%.o: src/module/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очищення
clean:
	del /Q $(TARGET).exe 2>nul
	del /Q $(OBJDIR)\*.o 2>nul

.PHONY: all clean

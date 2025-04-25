# === 配置 ===

NVME_LIB_DIR := ../libnvme/.build/src
NVME_LIB := $(NVME_LIB_DIR)/libnvme.a
NVME_INCLUDE_DIR := ../libnvme/src

CC := gcc -g 
CFLAGS := -Wall -Wextra -I./include -I./src/nvme -I$(NVME_INCLUDE_DIR)
LDFLAGS := -static -L$(NVME_LIB_DIR) $(NVME_LIB)

SRC_DIR := .
BUILD_DIR := build
TARGET := $(BUILD_DIR)/db_exec

# === 自動尋找所有 .c 檔案 ===
SRC_DIRS := $(shell find . -type d)
SRCS := $(wildcard $(foreach dir, $(SRC_DIRS), $(dir)/*.c))


# === 把 .c 對應成 build/*.o 檔案（保留子路徑）
OBJS := $(patsubst ./%.c,$(BUILD_DIR)/%.o,$(SRCS))

all: $(TARGET)

# 生成 target
$(TARGET): $(OBJS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# 編譯 .o，目標放到 build/
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# 清除
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean

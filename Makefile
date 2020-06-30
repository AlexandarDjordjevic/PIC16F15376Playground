CC=xc8
SOURCES=source/*.c
PROCESSOR=16f15376
INC_PATH=-I./include
OUTPU_DIR=build
OBJECT_DIR=build

all:
	$(CC) --chip=$(PROCESSOR) $(SOURCES) $(INC_PATH) --objdir=$(OBJECT_DIR) --outdir=$(OUTPU_DIR)

clean:
	rm -fr build/*
CC=xc8
SOURCES=source/*.c
PROCESSOR=16f15376
INC_PATH=-I./include
OUTPU_DIR=build
OBJECT_DIR=build
OUTPUT_FILE=app

all:
	if [ ! -d "$(OUTPU_DIR)" ]; then mkdir $(OUTPU_DIR); fi 
	$(CC) --chip=$(PROCESSOR) $(SOURCES) $(INC_PATH) --objdir=$(OBJECT_DIR) --outdir=$(OUTPU_DIR) -O$(OUTPUT_FILE)

clean:
	rm -fr build
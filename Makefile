#================================================
# User define parameter
#
PROGRAM = hello
CC = g++
LINK = g++
CFLAGS = -Wall 
#LDFLAGS = 

SRC_FILE_TYPE = cxx
SRC_DIR := src

LIBS := -lpthread -lm

LIBPATH := -L/usr/lib 
#LIBPATH := -L/usr/lib -L/usr/lib64

INCLUDE_PATH := -I$(SRC_DIR)/include -I$(SRC_DIR)

#define main source file in which "main()" function exist!
MAIN_FILE = main
#MAIN_FILE = $(PROGRAM)

# module define which act as subdirectory reside in "src" directory
#SRC_MODULES = main conf ca comm pm utils ic reg timer 
SRC_MODULES = main util

#==================================================
# Optional User define parameter
#

#debug/release mod : 0 or 1
DEBUG=1
ifeq ($(DEBUG),1)
BUILD_MODE := debug
else
BUILD_MODE := release
endif
#$(warning  "BUILD MODE is : $(BUILD_MODE)!")

#Auto dependent generated? (YES/NO)
#AUTO_DEPENDENT = YES
AUTO_DEPENDENT = NO

#=================================================
#directory define
BUILD_DIR := ./bin
DEPS_DIR := $(BUILD_DIR)/depend

#================================================= 
#get out put directory
ifeq ($(BUILD_MODE),debug)
OUTPUT_DIR := $(BUILD_DIR)/debug
CFLAGS += -DDEBUG -g -O0 

#add test directory in DEBUG mode
SRC_MODULES += test

else
ifeq ($(BUILD_MODE),release)
OUTPUT_DIR := $(BUILD_DIR)/release
CFLAGS += -DNDEBUG -O3 

else
$(error "BUILD_MODE error!(release/debug)")
endif
endif

##set target
target = $(PROGRAM)

#add path
#VPATH = $(shell find $(SRC_DIR) -type d)
#VPATH = $(SRC_DIR)
VPATH += $(addprefix $(SRC_DIR)/, $(SRC_MODULES))

#FIND_SRC_FILES = $(shell find $(SRC_DIR) -maxdepth 1 -name "*.$(SRC_FILE_TYPE)")
#SRC_FILES = $(notdir $(FIND_SRC_FILES) )

FIND_SRC_FILES = $(foreach dir, $(VPATH), $(wildcard $(dir)/*.$(SRC_FILE_TYPE)))
SRC_FILES = $(notdir $(FIND_SRC_FILES) )

OBJ_FILES = $(SRC_FILES:.$(SRC_FILE_TYPE)=.o)

#auto depend file?
ifeq ($(AUTO_DEPENDENT) ,YES)
DEP_FILES = $(SRC_FILES:.$(SRC_FILE_TYPE)=.d)
endif

OUTPUT_OBJS = $(addprefix $(OUTPUT_DIR)/,$(OBJ_FILES))
OUTPUT_DEPS = $(addprefix $(DEPS_DIR)/,$(DEP_FILES))

#INCLUDE_PATH += $(addprefix -I , $(VPATH))

##======  start of init shell ======##
## exec init shell command

$(shell mkdir -p "$(OUTPUT_DIR)")
$(shell mkdir -p "$(DEPS_DIR)")
#$(foreach dir, $(SRC_MODULES),$(shell mkdir -p "$(DEPS_DIR)/$(dir)"))

##======= end of init ==============##

#add target
.PHONY:all
all: $(BUILD_DIR)/$(target)

.PHONY: help
help:
	@echo "make's target is:  "
	@echo "		make all      --  make all and generate target!"
	@echo "		make run      --  make all and run the target! "
	@echo "		make clean    --  make clean the object files!"
	@echo "		make cleanall --  make clean all ,clean everything!"
	@echo "Test:"
	@echo "		make test     --  make  test target!"
	@echo "		make runtest  --  make test target and run it!"
	@echo "		make help     --  this help!"
	@echo " "
	@echo " "



## 
#link all objs and libs
$(BUILD_DIR)/$(target): $(OUTPUT_DIR)/$(MAIN_FILE).o $(OUTPUT_DEPS) $(OUTPUT_OBJS) 
	$(LINK) $(LIB_PATH)  $< $(OUTPUT_OBJS) $(CFLAGS) -o $@  $(LIBPATH) $(LIBS)
	@echo "Make '$(BUILD_DIR)/$(target)' finished!"
  
    
#compile source files into object files
$(OUTPUT_DIR)/%.o: %.$(SRC_FILE_TYPE) 
	$(CC) $(CFLAGS) $(INCLUDE_PATH) -I$(dir $<) -c $< -o $@

#src dir compiler
$(OUTPUT_DIR)/%.o: $(SRC_DIR)/%.$(SRC_FILE_TYPE)
	$(CC) $(CFLAGS) $(INCLUDE_PATH) -c $< -o $@

#
$(DEPS_DIR)/%.d: %.$(SRC_FILE_TYPE)
	@echo -n "$(OUTPUT_DIR)/" > $@
	$(CC) -MM $(INCLUDE_PATH) $< >> $@


.PHONY:test
test: $(OUTPUT_DIR)/test_main.o $(OUTPUT_DEPS) $(OUTPUT_OBJS)
	$(LINK) $(LIB_PATH) $(OUTPUT_OBJS) $(CFLAGS) $< -o $(BUILD_DIR)/$@ $(LIBPATH) $(LIBS)
	

.PHONY:testrun
testrun: test
	$(BUILD_DIR)/test

.PHONY:run
run: $(BUILD_DIR)/$(target)
	$(BUILD_DIR)/$(target)

.PHONY:clean
clean:
	-rm -rf $(OUTPUT_DIR)
	-rm -f $(BUILD_DIR)/$(target)

.PHONY:cleanall
cleanall:clean
	-rm -rf $(BUILD_DIR)/*

#dep files
-include $(OUTPUT_DEPS)

#=========== user custom target define here ===================================
.PHONY:snmp
snmp: $(OUTPUT_DIR)/snmp.o $(OUTPUT_DEPS) $(OUTPUT_OBJS)
	$(LINK) $(LIB_PATH) $(OUTPUT_OBJS) $(CFLAGS) $< -o $(BUILD_DIR)/$@ $(LIBPATH) $(LIBS)

#.PHONY:test
#test2: $(OUTPUT_DIR)/test2.o $(OUTPUT_DEPS) $(OUTPUT_OBJS)
#	$(LINK) $(LIB_PATH) $(OUTPUT_OBJS) $(CFLAGS) $< -o $(BUILD_DIR)/$@ $(LIBPATH) $(LIBS)

#.PHONY:test
#test3: $(OUTPUT_DIR)/test3.o $(OUTPUT_DEPS) $(OUTPUT_OBJS)
#	$(LINK) $(LIB_PATH) $(OUTPUT_OBJS) $(CFLAGS) $< -o $(BUILD_DIR)/$@ $(LIBPATH) $(LIBS)



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Line.cpp \
../src/LinkedList.cpp \
../src/Point.cpp \
../src/Production.cpp \
../src/Space.cpp \
../src/Systems\ Final.cpp \
../src/Tests.cpp 

OBJS += \
./src/Line.o \
./src/LinkedList.o \
./src/Point.o \
./src/Production.o \
./src/Space.o \
./src/Systems\ Final.o \
./src/Tests.o 

CPP_DEPS += \
./src/Line.d \
./src/LinkedList.d \
./src/Point.d \
./src/Production.d \
./src/Space.d \
./src/Systems\ Final.d \
./src/Tests.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Systems\ Final.o: ../src/Systems\ Final.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Systems Final.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



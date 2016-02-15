################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/myfifo1.c \
../src/myinfo2.c \
../src/server.c \
../src/sock.c 

O_SRCS += \
../src/server.o \
../src/sock.o 

OBJS += \
./src/myfifo1.o \
./src/myinfo2.o \
./src/server.o \
./src/sock.o 

C_DEPS += \
./src/myfifo1.d \
./src/myinfo2.d \
./src/server.d \
./src/sock.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



HEADERS =	\
	-I./headers/

SRCS =	\
	./srcs/main.c\
	./srcs/utils/salloc.c\
	./srcs/utils/parsing.c\
	./srcs/utils/cleanup.c\
	./srcs/utils/print_nbr.c\
	./srcs/utils/delta_utime.c\
	./srcs/utils/plog.c\
	./srcs/utils/check_death.c\
	./srcs/utils/dsleep.c\
	./srcs/utils/philo_stop.c\
	./srcs/init/data_init.c\
	./srcs/init/mutex_init.c\
	./srcs/init/populate.c\
	./srcs/init/thread_join.c\
	./srcs/simulation.c\
	./srcs/routine/thread_routine.c

OBJS =	\
	./build/main.o\
	./build/salloc.o\
	./build/parsing.o\
	./build/cleanup.o\
	./build/print_nbr.o\
	./build/delta_utime.o\
	./build/plog.o\
	./build/check_death.o\
	./build/dsleep.o\
	./build/philo_stop.o\
	./build/data_init.o\
	./build/mutex_init.o\
	./build/populate.o\
	./build/thread_join.o\
	./build/simulation.o\
	./build/thread_routine.o

DEPS =	\
	./build/main.d\
	./build/salloc.d\
	./build/parsing.d\
	./build/cleanup.d\
	./build/print_nbr.d\
	./build/delta_utime.d\
	./build/plog.d\
	./build/check_death.d\
	./build/dsleep.d\
	./build/philo_stop.d\
	./build/data_init.d\
	./build/mutex_init.d\
	./build/populate.d\
	./build/thread_join.d\
	./build/simulation.d\
	./build/thread_routine.d

$(BUILD_DIR):
	@mkdir -p $@

./build/main.o: ./srcs/main.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/salloc.o: ./srcs/utils/salloc.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/parsing.o: ./srcs/utils/parsing.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/cleanup.o: ./srcs/utils/cleanup.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/print_nbr.o: ./srcs/utils/print_nbr.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/delta_utime.o: ./srcs/utils/delta_utime.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/plog.o: ./srcs/utils/plog.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/check_death.o: ./srcs/utils/check_death.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/dsleep.o: ./srcs/utils/dsleep.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/philo_stop.o: ./srcs/utils/philo_stop.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/data_init.o: ./srcs/init/data_init.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/mutex_init.o: ./srcs/init/mutex_init.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/populate.o: ./srcs/init/populate.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/thread_join.o: ./srcs/init/thread_join.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/simulation.o: ./srcs/simulation.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

./build/thread_routine.o: ./srcs/routine/thread_routine.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -MD -MP -o $@ -c $<
	@echo -e $(BLUE)$(NAME)$(RESET) compiling: $@

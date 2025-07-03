# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    configure.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/20 05:19:01 by ethebaul          #+#    #+#              #
#    Updated: 2025/06/22 22:59:18 by ethebaul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include $(MKCOLOR)

configure: fclean
	@echo -n "HEADERS =	" > $(MKGENERATED)
	@for i in $$(find $(HEADERS_DIR) -type d);\
	do\
		echo "\\" >> $(MKGENERATED);\
		echo -n "	-I$$i" >> $(MKGENERATED);\
	done;
	@echo >> $(MKGENERATED)
	@echo >> $(MKGENERATED)
	@echo -n "SRCS =	" >> $(MKGENERATED)
	@for i in $$(find $(SRCS_DIR) -type f -name "*.c");\
	do\
		echo "\\" >> $(MKGENERATED);\
		echo -n "	$$i" >> $(MKGENERATED);\
	done;
	@echo >> $(MKGENERATED)
	@echo >> $(MKGENERATED)
	@echo -n "OBJS =	" >> $(MKGENERATED)
	@for i in $$(find $(SRCS_DIR) -type f -name "*.c");\
	do\
		echo "\\" >> $(MKGENERATED);\
		echo -n "	$(BUILD_DIR)$$(basename "$${i%.c}.o")" >> $(MKGENERATED);\
	done;
	@echo >> $(MKGENERATED)
	@echo >> $(MKGENERATED)
	@echo -n "DEPS =	" >> $(MKGENERATED)
	@for i in $$(find $(SRCS_DIR) -type f -name "*.c");\
	do\
		echo "\\" >> $(MKGENERATED);\
		echo -n "	$(BUILD_DIR)$$(basename "$${i%.c}.d")" >> $(MKGENERATED);\
	done;
	@echo >> $(MKGENERATED)
	@echo >> $(MKGENERATED)
	@echo "\$$(BUILD_DIR):" >> $(MKGENERATED)
	@echo "	@mkdir -p \$$@" >> $(MKGENERATED)
	@for i in $$(find $(SRCS_DIR) -type f -name "*.c");\
	do\
		echo >> $(MKGENERATED);\
		echo $(BUILD_DIR)$$(basename "$${i%.c}.o"): $$i "| \$$(BUILD_DIR)" >> $(MKGENERATED);\
		echo "	@\$$(CC) \$$(CFLAGS) \$$(HEADERS) -MD -MP -o \$$@ -c \$$<" >> $(MKGENERATED);\
		echo "	@echo -e \$$(BLUE)\$$(NAME)\$$(RESET) compiling: \$$@" >> $(MKGENERATED);\
	done;

.PHONY: configure

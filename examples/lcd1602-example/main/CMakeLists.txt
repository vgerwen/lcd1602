
set(req 1602_driver)

idf_component_register(SRCS "lcd1602-example.c"
                    INCLUDE_DIRS "."
                    REQUIRES ${req})

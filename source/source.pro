TEMPLATE = subdirs

SUBDIRS += \
    library \
    example
	
example.depends = library

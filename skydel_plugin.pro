TEMPLATE = subdirs

SUBDIRS += \
    source/library \
    source/example
	
example.depends = library

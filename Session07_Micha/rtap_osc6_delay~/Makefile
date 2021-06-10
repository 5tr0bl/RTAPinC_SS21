

lib.name = rtap_osc6_delay

class.sources = rtap_osc6_delay~.c
rtap_osc6_delay~.class.sources = vas_delay.c
rtap_osc6_delay~.class.sources += vas_osc.c
rtap_osc6_delay~.class.sources += vas_mem.c

datafiles = 

# include Makefile.pdlibbuilder from submodule directory 'pd-lib-builder'
PDLIBBUILDER_DIR=pd-lib-builder/

CC += $(INCLUDES)
# CC +=  -mavx -DVAS_USE_AVX

include $(PDLIBBUILDER_DIR)/Makefile.pdlibbuilder
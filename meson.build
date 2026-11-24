project('netlib', 'c', version: '1.0.0')

project_url = ''
project_url_issues = project_url + '/issues/new'

conf = configuration_data()

warnings = []

################################################################################
# Project info

prettyname = 'Netlib'
full_name  = 'Networking Library'

# General version
netlib_version = meson.project_version()

compiler = meson.get_compiler('c')
common_cflags = compiler.get_supported_arguments([
        '-pedantic',
        '-Wfloat-equal',
        '-Wshadow',
        '-Wpointer-arith',
        '-Winit-self',
        '-Wno-unused-function',
        '-Wno-unused-parameter',
        '-Wno-unreachable-code',
        '-Wstrict-prototypes',
    ])

incInclude = include_directories('include')
srcInclude  = include_directories('src')

subdir('src')

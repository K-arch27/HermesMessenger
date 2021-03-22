hermesmessenger_sources = [
  'main.c',
]

hermesmessenger_deps = [
  dependency('gio-2.0', version: '>= 2.50'),
  dependency('gtk+-3.0', version: '>= 3.22'),
  dependency('webkit2gtk-4.0', version: '>= 2.30.4')

]

gnome = import('gnome')

hermesmessenger_sources += gnome.compile_resources('hermesmessenger-resources',
  'hermesmessenger.gresource.xml',
  c_name: 'hermesmessenger'
)

executable('hermesmessenger', hermesmessenger_sources,
  dependencies: hermesmessenger_deps,
  install: true,
)

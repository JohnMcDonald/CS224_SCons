env = Environment(CC = 'gcc')

libcma = env.SharedLibrary("cma", "cma.c")

program1 = env.Program("ma.exe", ['ma.c'], CPPPATH='.', LIBS=['cma'], LIBPATH=['.'])

program2 = env.Program("cmaTest.exe", ['cmaTest.c'], CPPPATH='.', LIBS=["cma", "m"], LIBPATH=[".", "/usr/lib"])

install = env.Install('./LIBCMA', libcma)
env.Alias('install', './LIBCMA')

dist = env.Tar('scons.tar', ['ma.c', 'cmaTest.c', 'cma.c', 'cma.h', 'SConstruct'])

test = env.Command('test', ['ma.exe', 'cmaTest.exe', 'libcma.so'], ['LD_LIBRARY_PATH=. ./ma.exe', 'LD_LIBRARY_PATH=. ./cmaTest.exe 1024'])

Default(libcma, program1, program2, dist, test)

clean = env.Command('clean', ['scons.tar', './LIBCMA'], ['rm scons.tar', 'rm -r ./LIBCMA'])

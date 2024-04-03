# Load the files
set term png enhanced font 'Verdana,10'
set output 'runtime.png'
set xlabel 'number of iterations'
set ylabel 'time (s)'
set logscale x

plot [:][:]'macro.log' using 1:2 with points title 'macro',\
              'func.log' using 1:2 with points title 'function'

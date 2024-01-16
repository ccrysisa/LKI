set title "臺北月平均降雨量"
set xlabel "月份"
set ylabel "降雨量(毫米)"
set term png font "Noto Sans CJK TC,12"
set output "statistic.png"
set xtics 1, 1, 12
set key left

plot \
"data.csv" using 1:2 with linespoints linewidth 2 title "淡水", \
"data.csv" using 1:3 with linespoints linewidth 2 title "鞍部", \
"data.csv" using 1:4 with linespoints linewidth 2 title "臺北", \
"data.csv" using 1:5 with linespoints linewidth 2 title "基隆", \
"data.csv" using 1:6 with linespoints linewidth 2 title "竹子湖"

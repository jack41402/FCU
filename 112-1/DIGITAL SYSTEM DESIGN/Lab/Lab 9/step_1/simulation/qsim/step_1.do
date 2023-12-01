onerror {exit -code 1}
vlib work
vlog -work work step_1.vo
vlog -work work Waveform.vwf.vt
vsim -novopt -c -t 1ps -L cycloneiii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.step1_vlg_vec_tst -voptargs="+acc"
vcd file -direction step_1.msim.vcd
vcd add -internal step1_vlg_vec_tst/*
vcd add -internal step1_vlg_vec_tst/i1/*
run -all
quit -f

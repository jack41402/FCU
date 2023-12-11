onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /step_3/clk
add wave -noupdate /step_3/reset
add wave -noupdate /step_3/EO
add wave -noupdate /step_3/last_EO
add wave -noupdate /step_3/count
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {0 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 150
configure wave -valuecolwidth 100
configure wave -justifyvalue left
configure wave -signalnamewidth 0
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits ps
update
WaveRestoreZoom {0 ps} {1024 ns}
view wave 
wave clipboard store
wave create -driver freeze -pattern clock -initialvalue 0 -period 100ns -dutycycle 50 -starttime 0ns -endtime 1000ns sim:/step_3/clk 
wave create -driver freeze -pattern constant -value 1 -starttime 0ns -endtime 1000ns sim:/step_3/reset 
wave create -driver freeze -pattern clock -initialvalue 0 -period 100ns -dutycycle 50 -starttime 0ns -endtime 1000ns sim:/step_3/EO 
WaveCollapseAll -1
wave clipboard restore

view wave 
wave clipboard store
wave create -driver freeze -pattern constant -value 1 -starttime 0ns -endtime 1000ns sim:/step_3/EO 
wave create -driver freeze -pattern clock -initialvalue 0 -period 100ns -dutycycle 50 -starttime 0ns -endtime 1000ns sim:/step_3/clk 
wave create -driver freeze -pattern constant -value 1 -starttime 0ns -endtime 1000ns sim:/step_3/reset 
WaveCollapseAll -1
wave clipboard restore

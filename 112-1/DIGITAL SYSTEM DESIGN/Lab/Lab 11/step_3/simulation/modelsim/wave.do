view wave 
wave clipboard store
wave create -driver freeze -pattern clock -initialvalue 0 -period 100ns -dutycycle 50 -starttime 0ns -endtime 1000ns sim:/step_3/EO 
wave create -driver freeze -pattern clock -initialvalue 0 -period 50us -dutycycle 50 -starttime 0us -endtime 1000us sim:/step_3/clk 
wave create -driver freeze -pattern clock -initialvalue 0 -period 100ns -dutycycle 50 -starttime 0ns -endtime 1000ns sim:/step_3/EO 
wave create -driver freeze -pattern clock -initialvalue HiZ -period 50ns -dutycycle 50 -starttime 0ns -endtime 1000ns sim:/step_3/clk 
WaveCollapseAll -1
wave clipboard restore

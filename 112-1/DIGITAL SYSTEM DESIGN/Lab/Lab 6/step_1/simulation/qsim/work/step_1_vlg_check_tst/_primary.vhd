library verilog;
use verilog.vl_types.all;
entity step_1_vlg_check_tst is
    port(
        F               : in     vl_logic;
        F_complement    : in     vl_logic;
        sampler_rx      : in     vl_logic
    );
end step_1_vlg_check_tst;

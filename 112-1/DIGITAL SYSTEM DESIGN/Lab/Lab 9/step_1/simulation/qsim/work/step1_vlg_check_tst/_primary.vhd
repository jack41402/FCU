library verilog;
use verilog.vl_types.all;
entity step1_vlg_check_tst is
    port(
        d0              : in     vl_logic_vector(0 to 6);
        d1              : in     vl_logic_vector(0 to 6);
        sampler_rx      : in     vl_logic
    );
end step1_vlg_check_tst;

library verilog;
use verilog.vl_types.all;
entity step_2 is
    port(
        F_SOP           : out    vl_logic;
        B               : in     vl_logic;
        C               : in     vl_logic;
        D               : in     vl_logic;
        A               : in     vl_logic;
        F_POS           : out    vl_logic
    );
end step_2;

library verilog;
use verilog.vl_types.all;
entity step_1 is
    port(
        F               : out    vl_logic;
        D               : in     vl_logic;
        B               : in     vl_logic;
        C               : in     vl_logic;
        F_complement    : out    vl_logic;
        A               : in     vl_logic
    );
end step_1;

library verilog;
use verilog.vl_types.all;
entity step1_vlg_sample_tst is
    port(
        v               : in     vl_logic_vector(3 downto 0);
        sampler_tx      : out    vl_logic
    );
end step1_vlg_sample_tst;

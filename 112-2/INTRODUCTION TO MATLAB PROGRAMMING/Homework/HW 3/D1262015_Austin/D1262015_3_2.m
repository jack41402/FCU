for i = 1:5
    amount = input('Enter amounts for each resident: ');  % 让用户输入每位居民的金额
    if amount <= 500
        price = amount * 0.02 + 5;
    elseif amount > 500 && amount < 1000
        price = 10 + (amount - 500) * 0.05 + 5;
    else
        price = 35 + (amount - 1000) * 0.1 + 5;
    end
    fprintf('Price = %.2f\n', price);  % 输出价格
end




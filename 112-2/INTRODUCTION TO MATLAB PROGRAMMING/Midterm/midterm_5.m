format compact
format short
L = @(R) (4000-pi.*R.^2)./(4.*R);
fence = @(R) pi*R*50 + 2*(L(R)+R)*40;
% minimize the total cost of the fence
R_min = fminbnd(fence, 0, 100)
L_min = L(R_min)

% compute the minimum cost
format bank
min_cost = fence(R_min)
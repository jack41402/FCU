clear;

x=[273 278 283 288 293 298];
y=[4.579 6.543 9.209 12.788 17.535 23.756];

fits=fit(x', y', 'poly2');
plot(fits, x, y, '.');
T_285=feval(fits, 285)
T_300=feval(fits, 300)
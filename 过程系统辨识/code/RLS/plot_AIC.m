function [f1,f2]=plot_AIC(AIC)

f1=figure;
meshz(AIC);
title('AIC');
xlabel('nb');
ylabel('na');
set(gca,'xdir', 'reverse');
set(gca,'ydir', 'reverse');
set(gca,'xTick',1:10);
set(gca,'yTick',1:10);
set(findobj(get(gca,'Children'),'LineWidth',0.5),'LineWidth',2);
print(f1,'-dpng','AIC_nb');
f2=figure;
meshz(AIC');
title('AIC');
xlabel('na');
ylabel('nb');
set(gca,'xdir', 'reverse');
set(gca,'ydir', 'reverse');
set(gca,'xTick',1:10);
set(gca,'yTick',1:10);
set(findobj(get(gca,'Children'),'LineWidth',0.5),'LineWidth',2);
print(f2,'-dpng','AIC_na');

end
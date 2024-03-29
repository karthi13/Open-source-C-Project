#load ggplot for quick and dirty plotting
library(ggplot2)

#map controller id to name
controller <- function(id, headway) {
    ifelse(id == 0, ifelse(headway == 0.3, "ACC (0.3 s)", "ACC (1.2 s)"),
        ifelse(id == 1, "CACC",
            ifelse(id == 2, "PLOEG", "CONSENSUS")
        )
    )
}

load('../results/Sinusoidal.Rdata')
allData$controllerName <- controller(allData$controller, allData$headway)

p.speed <- ggplot(allData, aes(x=time, y=speed*3.6, col=factor(nodeId))) +
           geom_line() +
           facet_grid(controllerName~., scales='free_y')
ggsave('sinusoidal-speed.pdf', p.speed, width=16, height=9)
#print(p.speed)

p.distance <- ggplot(subset(allData, distance != -1), aes(x=time, y=distance, col=factor(nodeId))) +
              geom_line() +
              facet_grid(controllerName~., scales='free_y')
ggsave('sinusoidal-distance.pdf', p.distance, width=16, height=9)
#print(p.distance)

p.accel <- ggplot(allData, aes(x=time, y=acceleration, col=factor(nodeId))) +
           geom_line() +
           facet_grid(controllerName~., scales='free_y')
ggsave('sinusoidal-acceleration.pdf', p.accel, width=16, height=9)
#print(p.accel)

p.caccel <- ggplot(allData, aes(x=time, y=controllerAcceleration, col=factor(nodeId))) +
            geom_line() +
            facet_grid(controllerName~., scales='free_y')
ggsave('sinusoidal-controller-acceleration.pdf', p.caccel, width=16, height=9)
#print(p.caccel)

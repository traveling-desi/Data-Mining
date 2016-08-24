setwd("/Users/sarpotd/Desktop/Courses/Coursera/Data Analysis/Data Mining/Data Visualiztion/Programming 1/ProgrammingAssignment1Data/Data/")

## tempData1
rawtempData <- read.csv("ExcelFormattedGISTEMPDataCSV.csv", as.is=TRUE)
rownames(rawtempData) <- rawtempData[,1]
rawtempData <-rawtempData[,2:ncol(rawtempData)]
tempData <- apply(rawtempData[1:nrow(rawtempData)-1,2:13], 1, as.integer)
rownames(tempData) <- colnames(rawtempData)[1:12]
abstempData <- (tempData/100)+14
medianTemp <- apply(abstempData,2,median)
maxTemp <- apply(abstempData,2,max)
minTemp <- apply(abstempData,2,min)
year <- colnames(tempData)
plot.window(xlim=c(0,100),ylim=c(0,100))
par(pch=20)
plot(c(13.5,15), x=c(1880,2015), ylab="Temp(C)", xlab="Year", main="Plot of Temperatures Max, Median, Min for each year and Lowess Smoothing(1880-2014)")
points(medianTemp, x=year, col="black")
points(maxTemp, x=year, col="red")
points(minTemp, x=year, col="blue")
lines(lowess(maxTemp, x=year), col="red")
lines(lowess(medianTemp, x=year), col="black")
lines(lowess(minTemp, x=year), col="blue")
legend(x=1980, y=13.75, c("MaxTemp", "MedianTemp", "MinTemp"), lty=c(1,1,1), lwd=c(2.5,2.5,2.5), col=c("red","black","blue"))


## tempData2
rawtempData2 <- read.csv("ExcelFormattedGISTEMPData2CSV.csv", as.is=TRUE)
rownames(rawtempData2) <- rawtempData2[,1]
rawtempData2 <-rawtempData2[,2:ncol(rawtempData2)]
tempData2 <- apply(rawtempData2[1:nrow(rawtempData2)-1,1:3], 1, as.integer)
year <- colnames(tempData2)
rownames(tempData2) <- colnames(rawtempData2)[1:3]
abstempData2 <- (tempData2/100)+14
plot(c(13.5,15), x=c(1880,2015), ylab="Temp(C)", xlab="Year", main="Plot of Temperatures of NHemi, SHemi, Global (and Lowess smoothing)")
lines(abstempData2[1,], x=year, col="red")
lines(abstempData2[2,], x=year, col="blue")
lines(abstempData2[3,], x=year, col="black")
lines(lowess(abstempData2[1,], x=year), col="red", lwd=3.5)
lines(lowess(abstempData2[2,], x=year), col="blue", lwd=3.5)
lines(lowess(abstempData2[3,], x=year), col="black", lwd=3.5)
legend(x=1980, y=13.75, c("Global", "NHem", "SHem"), lty=c(1,1,1), lwd=c(2.5,2.5,2.5), col=c("red","blue","black"))



## Cycle in Temperatures between Northern, Southern and Global
year <- colnames(tempData2)
nHemiG = abstempData2[2,] - abstempData2[1,]
sHemiG = abstempData2[3,] - abstempData2[1,]
gG = abstempData2[1,] - abstempData2[1,]
plot(c(-0.2,0.2), x=c(1880,2015), ylab="Temp(C)", xlab="Year", main="Temperature Cycles between NHemi and SHemi Vs Global")
lines(nHemiG, x=year, col="red")
lines(sHemiG, x=year, col="blue")
lines(gG, x=year, col="black")
legend(x=1960, y=-0.15, c("nHemi-Global", "sHemi-Global", "Global"), lty=c(1,1,1), lwd=c(2.5,2.5,2.5), col=c("red","blue","black"))





## Not good
absDev = maxTemp - minTemp
plot(c(0.3,0.4), x=c(1880,2015), ylab="Temp(C)", xlab="Year")
points(y=absDev, year)
lines(lowess(absDev, x=year), col="blue")


#!/usr/bin/env Rscript

# importing the data

data1 = read.csv("./temp.csv")
#View(data1, 'temp.csv')
library(caTools)
set.seed(123)
datasplit = sample.split(data1$Salary, SplitRatio=0.75)
tra_data = subset(data1, datasplit=TRUE)
tes_data = subset(data1, datasplit=FALSE)
#View(tra_data)
#View(tes_data)

#data processing

# ifelse is ternary basically as ifelse(test, yes, no)
data1$Age = ifelse(is.na(data1$Age), ave(data1$Age, FUN = function(x) mean(x, na.rm=TRUE)), data1$Age)
data1$Salary = ifelse(is.na(data1$Salary), ave(data1$Salary, FUN = function(x) mean(x, na.rm=TRUE)), data1$Salary)
#View(data1)

#handling catergorical values
data1$Country=factor(data1$Country,levels=c('France', 'Spain', 'Germany'), labels=c(1,2,3))
data1$Purchased=factor(data1$Purchased,levels=c('Yes', 'No'),labels=c('Y', 'N'))
# View(data1)
# readLines(Sys.sleep(60))


# coercion

#x<-c(1.7)
x<-c(1.7,'a',TRUE)  # implicit
as.numeric(x)
as.character(x)
x
typeof(c)


# matrix
x <-matrix(nrow=3, ncol=3)
typeof(x)
class(x)
x
dim(x)
# x<-matrix(c(1:10), ncol=5)
x <- matrix(c(1:10), nrow=3, byrow=TRUE)
# check how to use 'dimnames' here
x

# binding two vectors(arrays) with matrix
x<-c(1:3)
y<-c(4:6)
rbind(x,y)  # row bind
rbind(y,x)  # row bind
cbind(x,y)
cbind(y,x)
y[2]  # shows that indexing starts from 1 in R

# list
x<-list(1,2,"a",TRUE,1+2i)
x
x[1]
y<-as.list(y)
y

# named attribute in list
x<-list(as="united",b=1:5)
x
names(x)
x[2]  # this will give 'b' attribute
# check how to access 3 element of b


# data frame

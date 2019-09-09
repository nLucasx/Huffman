library(ggplot2)

result <- read.table("colocar o caminho do arquivo de entrada", header = T)
head(result)
plot(result$Index, 
     result$List,
     type = "o",
     col = "blue",
     lwd = 2, 
     xlab = "Tamanho N",
     ylab = "Iterações",
     main = "Fila com Lista vs Heap")

lines(result$Index, result$Heap, type="o", col = "orange", lwd = 2)
legend("topleft", legend=c("Lista", "Heap"),
       col=c("blue", "orange"),  lty = 30, cex = 0.8)

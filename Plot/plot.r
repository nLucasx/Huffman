library(ggplot2)

result <- read.table("//home//alunoic//Área de Trabalho//Huffman//output.txt", header = T)
head(result)
plot(result$Index, 
     result$List,
     type = "l",
     col = "blue",
     lwd = 1, 
     xlab = "Elementos",
     ylab = "Iterações",
     main = "Fila vs heap")

lines(result$Index, result$Heap, type="l", col = "red", lwd = 1)
legend("topleft", legend=c("Lista", "Heap"),
       col=c("blue", "red"),  lty = 30, cex = 0.8)




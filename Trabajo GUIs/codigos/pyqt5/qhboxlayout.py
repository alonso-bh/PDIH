#Importamos system para permitir manejar el estado de salida.
import sys


#Importamos las clases necesarias.
from PyQt5.QtWidgets import QApplication
from PyQt5.QtWidgets import QHBoxLayout
from PyQt5.QtWidgets import QPushButton
from PyQt5.QtWidgets import QWidget

# Creamos un objeto QApplication para crear la aplicación, toda
# aplicación QtPy5 ha de crearlo. Proporcionándonos información global.
# Se le pasa sys.argv ya que utiliza el constructor para crear la aplicación
# utilizando argc y argv en c++.
app = QApplication(sys.argv)

# Creamos la ventana de la aplicación. es decir la GUI de la aplicación.
# Para ello nos bastamos con un QWidget.
window = QWidget()
window.setWindowTitle('QHBoxLayout')

#Establecemos el layout para la adición de widgets, en este caso botones.
layout = QHBoxLayout()
layout.addWidget(QPushButton('Left'))
layout.addWidget(QPushButton('Center'))
layout.addWidget(QPushButton('Right'))

#Añadiemos el layout a la ventana
window.setLayout(layout)
#Mostaramos la ventana.
window.show()
#Establecemos el bucle de enventos.
sys.exit(app.exec_())
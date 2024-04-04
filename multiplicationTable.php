<?php
$size = $_POST["size"];
if($size > 0) {

    echo "<h2>Multiplication Table for $size</h2>";
    echo "<table>";
    for($i = 1; $i <= $size; $i++) {
        echo "<tr>";
        for($j = 1; $j <= $size; $j++) {
            echo "<td>" . ($i * $j) . "</td>";

        }
        echo "</tr>";
    }
    echo "</table>";
} else {
    echo "<p>Enter a valid positive integer.</p>";
}
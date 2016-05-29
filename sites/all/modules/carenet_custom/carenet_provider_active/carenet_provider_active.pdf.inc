<?php
class PDF extends FPDF
{
  // Load data
  function LoadData($file)
  {
    // Read file lines
    $lines = file($file);
    $data = array();
    foreach($lines as $line)
      $data[] = explode(';',trim($line));
    return $data;
  }

  // Simple table
  function BasicTable($header, $data)
  {
    // Header
    foreach($header as $col)
      $this->Cell(40,7,$col,1);
    $this->Ln();
    // Data
    foreach($data as $row)
    {
      foreach($row as $col)
        $this->Cell(40,6,$col,1);
      $this->Ln();
    }
  }

  // Better table
  function ImprovedTable($header, $data)
  {
    // Column widths
    $w = array(40, 35, 40, 45);
    // Header
    for($i=0;$i<count($header);$i++)
      $this->Cell($w[$i],7,$header[$i],1,0,'C');
    $this->Ln();
    // Data
    foreach($data as $row)
    {
      $this->Cell($w[0],6,$row[0],'LR');
      $this->Cell($w[1],6,$row[1],'LR');
      $this->Cell($w[2],6,number_format($row[2]),'LR',0,'R');
      $this->Cell($w[3],6,number_format($row[3]),'LR',0,'R');
      $this->Ln();
    }
    // Closing line
    $this->Cell(array_sum($w),0,'','T');
  }

  // Colored table
  function FancyTable($header, $data)
  {
    // Colors, line width and bold font
    $this->SetFillColor(0,61,245);
    $this->SetTextColor(255);
    $this->SetDrawColor(31,94,255);
    //$this->SetLineWidth(.3);
    $this->SetLineWidth(.5);
    $this->SetFont('','B');
    // Header
    $w = array(30, 120, 40);
    for($i=0;$i<count($header);$i++)
      $this->Cell($w[$i],12,$header[$i],1,0,'C',true);
    $this->Ln();

    // Data
    $fill = true;
    $first = true;
    foreach($data as $row)
    {
      if (!$first) {
        // Color and font restoration
        $this->SetFillColor(224,235,255);
        $this->SetTextColor(0);
        $this->SetFont('');
      }

      $this->Cell($w[0],10,$row[0],'LR',0,'L',$fill);
      $this->Cell($w[1],10,$row[1],'LR',0,'L',$fill);
      //$this->MultiCell(100,10,$row[1],0,'L',$fill);
      $this->Cell($w[2],10,$row[2],'LR',0,'L',$fill);
      $first = false;

      //$this->Cell($w[2],6,number_format($row[2]),'LR',0,'R',$fill);
      $this->Ln();
      $fill = !$fill;
    }
    // Closing line
    $this->Cell(array_sum($w),0,'','T');
  }
  function NbLines($w,$txt)
  {
    //Computes the number of lines a MultiCell of width w will take
    $cw=&$this->CurrentFont['cw'];
    if($w==0)
      $w=$this->w-$this->rMargin-$this->x;
    $wmax=($w-2*$this->cMargin)*1000/$this->FontSize;
    $s=str_replace("\r",'',$txt);
    $nb=strlen($s);
    if($nb>0 and $s[$nb-1]=="\n")
      $nb--;
    $sep=-1;
    $i=0;
    $j=0;
    $l=0;
    $nl=1;
    while($i<$nb)
    {
      $c=$s[$i];
      if($c=="\n")
      {
        $i++;
        $sep=-1;
        $j=$i;
        $l=0;
        $nl++;
        continue;
      }
      if($c==' ')
        $sep=$i;
      $l+=$cw[$c];
      if($l>$wmax)
      {
        if($sep==-1)
        {
          if($i==$j)
            $i++;
        }
        else
          $i=$sep+1;
        $sep=-1;
        $j=$i;
        $l=0;
        $nl++;
      }
      else
        $i++;
    }
    return $nl;
  }
}
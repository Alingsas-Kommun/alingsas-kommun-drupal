
	<?php if ($exposed): ?>
    <div class="row cols-3 cf">
      <?php print $exposed; ?>
    </div>
  <?php endif; ?>

<!-- <form class="form-general">
		<div class="row cols-3 cf">
			<div class="col col-1 small">
				<div class="select">
				    <label for="select1">År</label>
				    <div class="custom-select-container"><select class="form-select replaced" name="select1" id="select1">
				    	<option value="option-1">Option 1</option>
				    	<option value="option-2">Option 2</option>
				    	<option value="option-3">Option 3</option>
				    </select><span class="custom-select" aria-hidden="true"><span><span>Option 1</span></span></span></div>
				</div>
			</div>
			<div class="col col-2 small">
				<div class="select">
				    <label for="select2">Månad</label>
				    <div class="custom-select-container"><select class="form-select replaced" name="select2" id="select2">
				    	<option value="option-1">Option 1</option>
				    	<option value="option-2">Option 2</option>
				    	<option value="option-3">Option 3</option>
				    </select><span class="custom-select" aria-hidden="true"><span><span>Option 1</span></span></span></div>
				</div>
			</div>
			<div class="col col-3 small form-actions">
				<input type="submit" value="Filtrera" name="submit">
			</div>
		</div>
	</form> -->
<div class="m news-listing company-news">
	  <?php if ($header): ?>
    <p>
      <?php print $header; ?>
    </p>
  <?php endif; ?>
	<?php if ($rows): ?>
      <?php print $rows; ?>
  <?php elseif ($empty): ?>
    <div class="view-empty">
      <?php print $empty; ?>
    </div>
  <?php endif; ?>
  <?php if ($pager): ?>
  <div class="paging cf">
    <?php print $pager; ?>
  </div>
  <?php endif; ?>

</div>
